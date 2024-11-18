-- 코드를 입력하세요
SELECT first_half.flavor
FROM first_half JOIN icecream_info ON first_half.flavor = icecream_info.flavor
WHERE total_order > 3000 AND ingredient_type = 'fruit_based'
ORDER BY total_order DESC;