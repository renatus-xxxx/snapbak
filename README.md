# build status

[![windows](https://github.com/renatus-xxxx/snapbak/workflows/windows/badge.svg)](https://github.com/renatus-xxxx/snapbak/actions?query=workflow%3Awindows)
[![macos](https://github.com/renatus-xxxx/snapbak/workflows/macos/badge.svg)](https://github.com/renatus-xxxx/snapbak/actions?query=workflow%3Amacos)
[![ubuntu](https://github.com/renatus-xxxx/snapbak/workflows/ubuntu/badge.svg)](https://github.com/renatus-xxxx/snapbak/actions?query=workflow%3Aubuntu)

<img src="https://raw.githubusercontent.com/renatus-xxxx/snapbak/main/images/tether.png" title="tether" />

# snapbak

**snapbak** is a lightweight command-line tool that creates automated backups of your files with version control. It appends a version number to the backup file name, ensuring you always have multiple versions of your important files without overwriting.

## Features

- Creates backup copies of specified files.
- Automatically increments version numbers for each backup (e.g., `file.00~`, `file.01~`).
- Simple and easy to use with a single command.
- Ideal for source code or document versioning.

## Usage
To create a backup, simply run:

snapbak <file_to_backup>

## Example
Here is an example of how snapbak works:

- You have a file called main.c.
- Running the command ./snapbak main.c creates a backup: main.00~.
- Running the same command again creates another backup: main.01~.
- This process ensures that older versions are retained, providing simple version control.

## Download
- [try on webmsx](https://webmsx.org/?MACHINE=MSXTRJ&DISKA_URL=https://raw.githubusercontent.com/renatus-xxxx/snapbak/main/bin/SNAPBAK.DSK&FAST_BOOT)
- [.DSK image(DOS for MSX v0.16 Gaku)](https://raw.githubusercontent.com/renatus-xxxx/snapbak/main/bin/SNAPBAK.DSK)
- [SNAPBAK.COM](https://raw.githubusercontent.com/renatus-xxxx/snapbak/main/bin/SNAPBAK.COM)