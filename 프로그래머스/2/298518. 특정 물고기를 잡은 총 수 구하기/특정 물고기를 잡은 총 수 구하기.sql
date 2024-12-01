-- 코드를 작성해주세요

SELECT COUNT(1) AS fish_count
FROM fish_info AS a JOIN fish_name_info AS b ON a.fish_type = b.fish_type
WHERE b.fish_name IN ('BASS', 'SNAPPER');