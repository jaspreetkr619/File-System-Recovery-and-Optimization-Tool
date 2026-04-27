# File System Recovery Tool
This project simulates a file system with features such as:
- File creation and management
- Directory structure handling
- Free space management
- File recovery system
- Optimization techniques

# Person 1 work
## Day 1 Progress 
- Created personal branch: `person1-core`
- Created project structure using GitHub online
- Added `File` class declaration and implementation
- Added `Directory` class declaration and implementation
- Added `main.cpp` to test the file system structure
- Implemented a basic simulation of files and directories

## Features Added in Day 1 
- Create a file with name and size
- Write content into a file
- Read file content
- Create directories
- Add files to directories
- Add subdirectories to directories
- List contents of a directory
  
## Day 2 Progress 
- Implemented file deletion (soft delete)
- Added search functionality for files
- Introduced basic free space tracking
- Updated main.cpp to test new features

## Features Added in Day 2
- Delete file (marked as deleted instead of removing)
- Search file within a directory
- Track storage usage (used space and free space)

## Day 3 Progress 
- Added `StorageManager` class
- Implemented block-based storage simulation
- Allocated blocks when files are created
- Freed blocks when files are deleted
- Integrated storage tracking in `main.cpp`

## Features Added in Day 3
- Storage divided into fixed-size blocks
- Block allocation for files
- Block deallocation after deletion
- Display current storage block status

## Day 4 Progress
- Implemented file access methods in the File class
- Added sequential access to read full file content
- Added direct access to read specific character positions
- Added range-based access to read partial file content
- Updated main.cpp to test file access functionalities

## Features Added in Day 4
- Sequential file access (read entire file)
- Direct access (read character at a specific position)
- Partial access (read a range of content)

## Day 5 Progress 
- Added file recovery functionality
- Restored deleted files using soft delete mechanism
- Updated `main.cpp` to test recovery
- Restored storage blocks and used space after recovery

## Features Added in Day 5
- Recover deleted file by name
- Re-display recovered file in directory listing
- Restore storage usage after file recovery

## Day 6 Progress
- Improved deleteFile() to handle already deleted files
- Improved recoverFile() to handle already active files
- Added showAllContents() for debugging and demonstration
- Added helper function to count active files in a directory
- Added storage summary functions to count used and free blocks
- Updated `main.cpp` to test all new features

## Features Added in Day 6
- Safe deletion handling (prevents double deletion)
- Safe recovery handling (prevents invalid recovery)
- Debug listing to display deleted and active files
- Active file count for directories
- Storage usage summary (used and free blocks)

## Day 7 Progress 
- Organized `main.cpp` into structured demo sections
- Improved output readability using clear headings
- Added system summary section for final results
- Performed final testing and validation of all features
- Cleaned and prepared project for submission

## Features Added in Day 7
- Structured program flow for demonstration
- Section-based output (creation, access, delete, recovery, summary)
- Final system summary display
- Improved readability and presentation

# Person 2 work
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

## Day 5 Progress (Person 2)
- Continued work on `person2-core` branch
- Implemented file-to-block mapping system
- Improved storage management during file deletion
- Removed dependency on manual block tracking

## Current Day 5 Features
- Track storage blocks used by each file
- Automatically free correct blocks on deletion
- Maintain mapping between files and storage usage
- Improved accuracy of storage management

## Day 6 Progress (Person 2)
- Continued work on `person2-core` branch
- Implemented file recovery system
- Added soft delete mechanism
- Added restore functionality for deleted files

## Current Day 6 Features
- Soft delete (file not permanently removed)
- Store deleted file metadata
- Restore deleted files
- Reallocate storage during recovery
- Improved reliability of file system

## Day 7 Progress (Person 2)
- Completed DirectoryManager module
- Implemented CLI-based interface
- Integrated all features from Day 1 to Day 6
- Performed testing and validation

## Current Day 7 Features
- Command-based file system interaction
- Create/delete/restore/search files
- Directory management
- Storage management integration
- File recovery system
- End-to-end working system

# Person 3 work
## Day 1 – Branch Setup and Initial Development
- Created separate branches for individual contributions:
- feature/disk-management (Person-1)
- feature/directory-access (Person-2)
- feature/recovery-ui (Person-3)
Person-3:
- Implemented basic logging system (logs.txt)
- Designed transaction structure using START and COMMIT logs
- Person-1 & Person-2:
- Began development of core modules (File, Directory, Storage)
- Initial testing of individual modules

## Day 2 – Cache and Recovery Logic Implementation
- Developed cache system (cache.txt, cache_stats.txt)
- Implemented cache hit and miss logic
- Added crash simulation functionality
- Built recovery mechanism using transaction logs
- Verified logging, crash, and recovery flow through test cases

## Day 3 – Backend Integration (Flask Setup)
- Developed Flask backend (app.py)
- Connected C++ core logic with Flask using subprocess
- Implemented API endpoints:
/transaction, /crash, /recovery, /cache
- Tested backend execution and ensured correct output handling

## Day 4 – Frontend Development and UI Integration
- Designed frontend using HTML, CSS, and JavaScript
- Created UI sections:
- Input parameters
- Core operations
- System operations
- Connected frontend with Flask APIs
- Fixed UI issues (button handling, output display, preventing page reload)
- Completed initial UI testing

## Day 5 – First Integration (Person-1 and Person-3)
- Merged Person-1 (Storage Core) with Person-3 (Recovery & UI)
- Resolved conflicts in main.cpp (multiple main function issue)
- Integrated cache logic into main execution flow
- Fixed compilation errors and ensured system runs with backend + UI
- Verified functionality:
- Transaction
- Cache
- Recovery

## Day 6 – Final Integration (Person-2 Modules)
- Integrated Person-2 modules (Directory, File, Storage)
- Compared and verified core files (no structural conflicts found)
- Ensured compatibility of all modules within single system
- Added directory-related functionalities:
- File listing
- File searching
- Performed full system testing after integration

## Day 7 – Final Enhancements and Deployment Preparation
- Implemented real file system interaction (data/files/)
- Improved system behavior for realistic file handling
- Restructured project for Flask:
- Moved files into templates/ and static/ folders
- Enhanced UI:
- Added background image
- Improved layout, spacing, and readability
- Increased input and button sizes
- Fixed routing issues (/ endpoint using render_template)
- Cleaned project for deployment:
- Added .gitignore
- Removed unnecessary runtime files
- Prepared documentation and README
- Final testing and validation of complete system