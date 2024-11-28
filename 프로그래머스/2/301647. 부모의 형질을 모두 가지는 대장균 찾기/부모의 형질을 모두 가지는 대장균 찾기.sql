-- 코드를 작성해주세요
SELECT b.id, b.genotype, a.genotype AS parent_genotype
FROM ecoli_data AS a JOIN ecoli_data AS b ON a.id = b.parent_id
WHERE a.genotype & b.genotype = a.genotype
ORDER BY b.id ASC;