SELECT * FROM Employees WHERE EmployeeID = 3;

DELETE FROM Employees WHERE EmployeeID = 3;

CREATE TABLE Departments (
  DepartmentID INT PRIMARY KEY,
  DepartmentName VARCHAR(100) UNIQUE,
  ManagerID INT,
  FOREIGN KEY (ManagerID) REFERENCES Employees (EmployeeID)
)

CREATE TABLE SalaryLog (
  LogId INT PRIMARY KEY AUTO_INCREMENT,
  EmployeeID INT 
  OldSalary DECIMAL(10, 2)
  NewSalary DECIMAL(10, 2)
  ChangeDate TIMESTAMPS DEFAULT CURRENT_TIMESTAMP,
  FOREIGN KEY (EmployeeID) REFERENCES Employees(EmployeeID)
)

CREATE TRIGGER afterSalaryUpdate
AFTER UPDATE ON Employees
FOR EACH ROW
BEGIN
  IF OLD.salary <> NEW.salary THEN
    INSERT INTO SalaryLog (EmployeeID, OldSalary, NewSalary, ChangeDate)
    VALUE( NEW.EmployeeID, OLD.salary, NEW.salary, NOW())
    END IF;
END$$

DELIMITER;