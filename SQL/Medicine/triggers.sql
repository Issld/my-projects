CREATE OR REPLACE FUNCTION cascade_delete_fun() RETURNS TRIGGER AS $$
BEGIN
DELETE FROM worker_flu WHERE person_id = OLD.person_id;
DELETE FROM worker_vac WHERE person_id = OLD.person_id;
RETURN OLD;
END;
$$ LANGUAGE plpgsql;

CREATE OR REPLACE TRIGGER cascade_delete
BEFORE DELETE ON worker
FOR EACH ROW
EXECUTE PROCEDURE cascade_delete_fun();

CREATE OR REPLACE TRIGGER cascade_delete
BEFORE DELETE ON student
FOR EACH ROW
EXECUTE PROCEDURE cascade_delete_fun();

CREATE OR REPLACE FUNCTION cascade_update_fun() RETURNS TRIGGER AS $$
BEGIN
ALTER TABLE worker_flu DISABLE TRIGGER worker_flu_update;
UPDATE worker_flu SET person_id = NEW.person_id WHERE person_id = OLD.person_id;
ALTER TABLE worker_flu ENABLE TRIGGER worker_flu_update;
ALTER TABLE worker_vac DISABLE TRIGGER worker_vac_update;
UPDATE worker_vac SET person_id = NEW.person_id WHERE person_id = OLD.person_id;
ALTER TABLE worker_vac ENABLE TRIGGER worker_vac_update;
RETURN OLD;
END;
$$ LANGUAGE plpgsql;

CREATE OR REPLACE TRIGGER cascade_update
BEFORE UPDATE ON worker
FOR EACH ROW
EXECUTE PROCEDURE cascade_update_fun();

CREATE OR REPLACE TRIGGER cascade_update
BEFORE UPDATE ON student
FOR EACH ROW
EXECUTE PROCEDURE cascade_update_fun();

CREATE OR REPLACE FUNCTION input_fun() RETURNS TRIGGER AS $$
BEGIN
IF EXISTS (SELECT * FROM worker WHERE person_id = NEW.person_id) 
THEN RETURN NEW;
END IF;
RETURN OLD;
END;
$$ LANGUAGE plpgsql;

CREATE OR REPLACE TRIGGER worker_flu_update
BEFORE UPDATE ON worker_flu
FOR EACH ROW
EXECUTE PROCEDURE input_fun();

CREATE OR REPLACE TRIGGER worker_flu_insert
BEFORE INSERT ON worker_flu
FOR EACH ROW
EXECUTE PROCEDURE input_fun();

CREATE OR REPLACE TRIGGER worker_vac_update
BEFORE UPDATE ON worker_vac
FOR EACH ROW
EXECUTE PROCEDURE input_fun();

CREATE OR REPLACE TRIGGER worker_vac_insert
BEFORE INSERT ON worker_vac
FOR EACH ROW
EXECUTE PROCEDURE input_fun();