CREATE OR REPLACE FUNCTION inv(_id integer) RETURNS varchar(50) AS $$
DECLARE inv_val bool;
BEGIN
SELECT isInspected INTO inv_val FROM worker WHERE _id = person_id;
IF inv_val = TRUE THEN inv_val = FALSE;
ELSE inv_val = TRUE;
END IF;
UPDATE worker SET isInspected = inv_val WHERE _id = person_id;
RETURN 'Operation complete';
END;
$$ LANGUAGE plpgsql;

/*
DROP OPERATOR !(none, integer);
DROP FUNCTION inv(_id integer);
*/

CREATE OPERATOR ! (
	rightarg = integer,
	procedure = inv
);

SELECT !person_id AS status FROM worker WHERE person_id = 2;

CREATE OR REPLACE FUNCTION high_sum_fun(state points, value points)
RETURNS points AS $$
BEGIN
IF (value.russian + value.math + value.other) IS NULL THEN
RETURN state;
ELSE 
IF (state.russian + state.math + state.other) IS NULL OR (value.russian + value.math + value.other) > (state.russian + state.math + state.other) THEN
RETURN value;
END IF;
RETURN state;
END IF;
END;
$$ LANGUAGE plpgsql;

CREATE OR REPLACE FUNCTION get_points(EGE points)
RETURNS int AS $$
BEGIN
    RETURN EGE.russian + EGE.math + EGE.other;
END;
$$ LANGUAGE plpgsql;

CREATE OR REPLACE AGGREGATE high_summ (points) (
    sfunc = high_sum_fun,
    stype = points
);

SELECT * FROM student WHERE get_points(EGE) IN (SELECT get_points(high_summ(EGE)) FROM student);