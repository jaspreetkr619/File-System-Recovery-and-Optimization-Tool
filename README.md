# File System Recovery Tool
This project simulates a file system with features such as:
- File creation and management
- Directory structure handling
- Free space management
- File recovery system
- Optimization techniques

## Day 1 Progress (Person 2)
- Created personal branch: `person2-core`
- Added `DirectoryManager` class in core module
- Integrated with existing `Directory` class
- Implemented basic folder creation functionality
- Implemented directory listing functionality
- Ensured compatibility with existing project structure

## Current Day 1 Features
- Initialize root directory
- Create folders inside current directory
- List directory contents
- Maintain separate directory management layer

## Day 2 Progress (Person 2)
- Continued work on `person2-core` branch
- Added file creation functionality in DirectoryManager
- Integrated File and Directory classes
- Added file search functionality using existing Directory methods

## Current Day 2 Features
- Create files inside current directory
- Search files within directory
- Integrate file operations with directory structure
- List files and directories together

## Day 3 Progress (Person 2)
- Continued work on `person2-core` branch
- Integrated StorageManager with DirectoryManager
- Added storage allocation during file creation
- Added storage deallocation during file deletion

## Current Day 3 Features
- Allocate storage blocks when creating files
- Free storage blocks when deleting files
- Maintain synchronization between directory and storage
- Improved file management with storage tracking

## Day 4 Progress (Person 2)
- Continued work on `person2-core` branch
- Implemented automatic block calculation for files
- Removed manual block input dependency
- Improved integration with StorageManager

## Current Day 4 Features
- Automatically calculate required storage blocks
- Allocate storage based on file size
- Simplified file creation interface
- Improved storage management abstraction
