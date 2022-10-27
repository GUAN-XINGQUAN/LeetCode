/*
SQL syntax:
    column LIKE pattern
    '%' is used to represent string segment.
*/

SELECT patient_id, patient_name, conditions
FROM Patients
WHERE conditions LIKE 'DIAB1%' or conditions LIKE '% DIAB1%'