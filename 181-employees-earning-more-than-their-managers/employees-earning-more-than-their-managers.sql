# Write your MySQL query statement below
Select e.name AS Employee
from Employee e
INNER join Employee m
on  e.managerId=m.id
where e.salary>m.salary
