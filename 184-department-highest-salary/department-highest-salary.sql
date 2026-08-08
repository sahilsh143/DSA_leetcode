# Write your MySQL query statement below
Select d.name as Department,
e.name as Employee,
e.salary as Salary
from Employee e
JOIN Department as d
on e.departmentId=d.id
where e.salary=(SELECT MAX(e2.salary)
    FROM Employee e2
    WHERE e2.departmentId = e.departmentId);
