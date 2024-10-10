WITH A AS (
    SELECT ID, 
           SIZE_OF_COLONY,
           ROW_NUMBER() OVER (ORDER BY SIZE_OF_COLONY DESC) AS NUM,
           COUNT(*) OVER() AS total_count
    FROM ECOLI_DATA
)
SELECT ID,
       CASE
           WHEN NUM <= total_count / 4 THEN 'CRITICAL'
           WHEN NUM <= total_count / 4 * 2 THEN 'HIGH'
           WHEN NUM <= total_count / 4 * 3 THEN 'MEDIUM'
           ELSE 'LOW'
       END AS COLONY_NAME
FROM A
ORDER BY ID;