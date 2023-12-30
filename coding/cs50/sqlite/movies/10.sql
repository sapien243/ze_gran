SELECT name FROM people WHERE id IN (
    SELECT DISTINCT(person_id) FROM directors
    JOIN ratings ON directors.movie_id = ratings.movie_id
    WHERE rating >= 9.0
);