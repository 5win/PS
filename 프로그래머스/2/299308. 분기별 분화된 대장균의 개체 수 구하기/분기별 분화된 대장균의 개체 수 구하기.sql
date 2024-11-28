-- 코드를 작성해주세요
SELECT CONCAT(QUARTER(differentiation_date), 'Q') AS quarter, COUNT(*) AS ecoli_count
FROM ecoli_data
GROUP BY quarter
ORDER BY quarter;