-- 코드를 작성해주세요
SELECT CONCAT(b.quarter, 'Q') AS quarter, COUNT(*) AS ecoli_count
FROM ecoli_data AS a
	JOIN (SELECT QUARTER(differentiation_date) AS quarter, id
         FROM ecoli_data) AS b
   	ON a.id = b.id
GROUP BY b.quarter
ORDER BY quarter;
