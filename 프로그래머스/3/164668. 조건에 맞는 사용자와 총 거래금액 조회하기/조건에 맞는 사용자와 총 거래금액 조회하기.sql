-- 코드를 입력하세요
select u.user_id, u.nickname, b.total_sales
from used_goods_user as u
	inner join (select writer_id, sum(price) as total_sales
               from used_goods_board
               where status = 'DONE'
               group by writer_id) as b
	on u.user_id = b.writer_id
where b.total_sales >= 700000
order by b.total_sales asc