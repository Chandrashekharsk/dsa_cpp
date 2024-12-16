-- Create Employees table
CREATE TABLE Employees (
  EmployeeId INT PRIMARY KEY,
  Name VARCHAR(100),
  Department VARCHAR(50),
  Salary DECIMAL(10, 2)  -- Missing comma was added here
);

-- Insert records into Employees table
INSERT INTO Employees (EmployeeId, Name, Department, Salary)
VALUES
  (1, 'Alice', 'HR', 50000.00),
  (2, 'Bob', 'IT', 75000.00),
  (3, 'Charlie', 'Finance', 60000.00);

-- Update salary of employee with EmployeeId = 1
UPDATE Employees
SET Salary = 55000.00
WHERE EmployeeId = 1;

-- Delete employee with EmployeeId = 3
DELETE FROM Employees
WHERE EmployeeId = 3;

-- Create Departments table
CREATE TABLE Departments (
  DepartmentID INT PRIMARY KEY,
  DepartmentName VARCHAR(50) UNIQUE,
  ManagerId INT,
  FOREIGN KEY (ManagerId) REFERENCES Employees(EmployeeId)
);
