-- 코드를 입력하세요
SELECT B.title, B.board_id, R.reply_id, R.writer_id, R.contents, DATE_FORMAT(R.created_date, '%Y-%m-%d')
FROM used_goods_board AS B JOIN used_goods_reply AS R ON B.board_id = R.board_id
WHERE B.created_date BETWEEN '2022-10-1' AND '2022-10-31'
ORDER BY R.created_date ASC, B.title ASC;