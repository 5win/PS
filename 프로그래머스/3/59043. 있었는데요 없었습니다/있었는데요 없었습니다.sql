-- 코드를 입력하세요

select ins.animal_id, ins.name
from animal_ins as ins
	inner join animal_outs as outs
    on ins.animal_id = outs.animal_id
where ins.datetime >= outs.datetime
order by ins.datetime asc