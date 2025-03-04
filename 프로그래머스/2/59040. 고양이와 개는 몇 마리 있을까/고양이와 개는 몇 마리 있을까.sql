select animal_type, count(1) as count
from animal_ins
group by animal_type
order by 1 asc