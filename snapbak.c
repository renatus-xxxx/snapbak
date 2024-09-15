#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Check if the file exists by trying to open it
int file_exists(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file != NULL) {
        fclose(file);
        return 1; // File exists
    }
    return 0; // File does not exist
}

// Function to remove the extension from a filename
void remove_extension(char* filename) {
    char* dot = strrchr(filename, '.'); // Find the last occurrence of '.'
    if (dot != NULL) {
        *dot = '\0'; // Replace the dot with null terminator to remove the extension
    }
}

// Generate the backup file name in the format backup/filename.00~
void generate_backup_filename(char* buffer, int max_length, const char* base_filename, int version) {
    snprintf(buffer, max_length, "%s.%02d~", base_filename, version);
}

int main(int argc, char* argv[]) {
    FILE* source_file, * backup_file;
    char buffer[256];
    char base_filename[256];
    int version = 0;

    // Check if the correct number of command line arguments is provided
    if (argc != 2) {
        printf("Usage: %s <source_file>\n", argv[0]);
        return 1;
    }

    // Get the source file path from the command line argument
    const char* source_file_path = argv[1];

    // Extract the base file name from the path (remove directory parts)
#if defined(WIN32)
    const char* file_name_start = strrchr(source_file_path, '\\');
#elif defined(__APPLE__) || defined(__linux__)
    const char* file_name_start = strrchr(source_file_path, '/');
#else
    const char* file_name_start = source_file_path;
#endif

    // Move past the directory separator if present
#if defined(WIN32) || defined(__APPLE__) || defined(__linux__)
    file_name_start = (file_name_start != NULL) ? file_name_start + 1 : source_file_path;
#endif

    // Copy the file name to a modifiable buffer
    strncpy(base_filename, file_name_start, sizeof(base_filename) - 1);
    base_filename[sizeof(base_filename) - 1] = '\0'; // Ensure null termination

    // Remove the file extension from the base filename
    remove_extension(base_filename);

    // Check if the source file exists
    if (!file_exists(source_file_path)) {
        printf("Error: %s not found.\n", source_file_path);
        return 1;
    }

    // Increment the version number until a non-existing backup file is found
    while (1) {
        generate_backup_filename(buffer, sizeof(buffer), base_filename, version);
        if (!file_exists(buffer)) {
            break; // Backup file name is available
        }
        version++;
    }

    // Open the source file for reading
    source_file = fopen(source_file_path, "r");
    if (source_file == NULL) {
        printf("Error: Unable to open %s.\n", source_file_path);
        return 1;
    }

    // Open the backup file for writing
    backup_file = fopen(buffer, "w");
    if (backup_file == NULL) {
        printf("Error: Unable to create backup file %s.\n", buffer);
        fclose(source_file);
        return 1;
    }

    // Copy the contents of the source file to the backup file
    char ch;
    while ((ch = fgetc(source_file)) != EOF) {
        fputc(ch, backup_file);
    }

    // Display a message indicating the backup was created
    printf("Backup created: %s\n", buffer);

    // Close both files
    fclose(source_file);
    fclose(backup_file);

    return 0;
}
