-- 코드를 작성해주세요
SELECT COUNT(1) AS count
FROM ecoli_data
WHERE (genotype & 2) = 0 AND ((genotype & 1) OR (genotype & 4))