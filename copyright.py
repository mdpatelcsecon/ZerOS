#!/usr/bin/env python3

import sys
import datetime

# Define the GPL notice
GPL_NOTICE = """\
/* This file is part of the Aster project.
 *
 * Copyright (C) {year} Mohit D. Patel
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */
"""

# Check if the correct number of arguments were provided
if len(sys.argv) != 3:
    print(f"Usage: {sys.argv[0]} <file_path> <-c/-s>")
    sys.exit(1)

# Extract the file path and flag from the command line arguments
file_path = sys.argv[1]
file_type = sys.argv[2]

# Determine the appropriate comment syntax based on the file type
if file_type == "-c":
    comment_start = "/*"
    comment_end = "*/"
elif file_type == "-s":
    comment_start = ";"
    comment_end = ""
else:
    print("Invalid file type specified. Use -c for C files or -s for assembly files.")
    sys.exit(1)

# Open the file and read its contents
try:
    with open(file_path, "r") as f:
        contents = f.read()
except FileNotFoundError:
    print(f"File not found: {file_path}")
    sys.exit(1)

# Check if the file already has a GPL notice
if "GNU General Public License" in contents:
    # Update the year in the existing notice
    year = datetime.datetime.now().year
    new_contents = contents.replace("{year}", str(year))
else:
    # Add the GPL notice to the top of the file
    year = datetime.datetime.now().year
    new_contents = GPL_NOTICE.format(year=year) + "\n\n" + contents

# Write the updated contents back to the file
try:
    with open(file_path, "w") as f:
        f.write(new_contents)
except:
    print(f"Error writing to file: {file_path}")
    sys.exit(1)

print(f"Updated GPL notice in file: {file_path}")
