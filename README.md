# Student Record Management System

<div align="center">
  <img src="https://img.shields.io/badge/Language-C-blue.svg" alt="Language">
  <img src="https://img.shields.io/badge/Functionality-CRUD-green.svg" alt="Functionality">
  <img src="https://img.shields.io/badge/Storage-File%20Based-orange.svg" alt="Storage">
  <img src="https://img.shields.io/badge/Interface-CLI-yellow.svg" alt="Interface">
</div>

## 📋 Description

Student Record Management System is a command-line application written in C that allows users to manage student records. The system provides functionality for adding, searching, updating, and removing student information, as well as viewing all stored records. Data is persisted in a text file, making it a simple but effective solution for basic student record management needs.

## ✨ Features

- **Add New Students**: Register students with unique roll numbers
- **Search for Students**: Find students by roll number or name
- **Update Student Details**: Modify existing student information
- **Remove Student Records**: Delete student entries from the system
- **View All Records**: Display a tabulated list of all stored student records
- **Data Persistence**: All records are stored in a text file
- **Input Validation**: Prevents duplicate roll numbers and handles errors
- **Colored Output**: Improved readability with color-coded messages

## 💻 Technical Implementation

### Data Structure

The program uses a struct to represent student data:

```c
struct Add_Student
{
    char Roll[10];    // Student roll number (unique identifier)
    char Name[100];   // Student name
    char grade[5];    // Academic grade
    char phone[20];   // Contact phone number
};
```

### File Storage

Student records are stored in a comma-separated values (CSV) format in `student.txt`:

```
roll_number,student_name,grade,phone_number
```

### Functions

- `Add_Student()`: Adds a new student with validation for duplicate roll numbers
- `Search_Student()`: Locates a student record by roll number or name
- `Update_Details()`: Modifies existing student information
- `Remove_Student()`: Deletes a student record from the database
- `View_Records()`: Displays all student records in a tabular format

## 🔧 Compilation and Execution

### Prerequisites
- GCC compiler or any standard C compiler
- Terminal or Command Prompt

### Compilation
```bash
gcc -o student_management student_management.c
```

### Running the Program
```bash
./student_management
```

On Windows:
```cmd
student_management.exe
```

## 🚀 Usage Guide

### Main Menu
Upon launching the program, you'll see the main menu with these options:

```
=================Student Record Management System=================

                    1. Add a New Student
                    2. Search for a Student
                    3. Update Student Details
                    4. Remove a Student Record
                    5. View All Records
                    0. Exit
                    Choose Between (0-5):
```

### Adding a Student
1. Select option `1`
2. Enter roll number (must be unique)
3. Enter student name
4. Enter grade
5. Enter phone number

### Searching for a Student
1. Select option `2`
2. Enter roll number or full name to search

### Updating Student Details
1. Select option `3`
2. Enter roll number of student to update
3. Enter new name, grade, and phone number

### Removing a Student
1. Select option `4`
2. Enter roll number of student to remove

### Viewing All Records
1. Select option `5` to display all student records in tabular format

## 🌟 Future Enhancements

- Password protection for administrative operations
- Data export to CSV/Excel formats
- Search by partial name or other fields
- Sorting options (by name, roll number, grade)
- Backup and restore functionality
- Student attendance tracking
- Performance metrics and reporting
- User privilege levels (admin/viewer)

## 🔍 Error Handling

The program includes several error handling mechanisms:
- Checks for file opening errors
- Validates unique roll number entries
- Provides user feedback through colored error messages
- Verifies record existence before update/delete operations

## 👨‍💻 Author

Created by Mayank Kumar

---

<div align="center">
  <p>Made with ❤️ for educational purposes</p>
</div>
