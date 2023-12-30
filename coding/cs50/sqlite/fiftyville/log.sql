-- Keep a log of any SQL queries you execute as you solve the mystery.

-- Find the report on the theft
SELECT id, description FROM crime_scene_reports
WHERE day=28 AND month=7 AND year=2021 AND street = "Humphrey Street";
-- Produces 2 cases, the required case id = 295
-- time = 10:15am, interviewed 3 witnesess on the same day, each mentioned the bakery

-- Look at the interviews
SELECT id, name, transcript FROM interviews
WHERE day=28 AND month=7 AND year=2021;
-- The 3 witnesses are 161=Ruth, 162=Eugene, 163=Raymond
-- Ruth -> bakery security footage from around 10:15am, look for cars leaving the parking lot
-- Eugene -> bakery = Emma's bakery, saw theif at ATM on Leggett Street withdrawing money earlier the same day
-- Raymond -> theif called other for <1 min, to take earliest flight out tomorrow, other to purchase tickets

-- Look for identity of the theif with info from witnesses
SELECT name FROM people WHERE phone_number IN (
    SELECT caller FROM phone_calls
    WHERE day=28 AND month=7 AND year=2021 AND duration<60
) AND license_plate IN (
    SELECT license_plate FROM bakery_security_logs
    WHERE day=28 AND month=7 AND year=2021 AND hour=10 AND minute<30 AND activity="exit"
) AND id IN (
    SELECT person_id FROM bank_accounts WHERE account_number IN (
        SELECT account_number FROM atm_transactions
        WHERE day=28 AND month=7 AND year=2021 AND atm_location="Leggett Street" AND transaction_type="withdraw"
    )
);
-- lists 2 people: Diana, Bruce --suspected theif

-- Look for identity of receivers
SELECT name FROM people WHERE phone_number IN (
    SELECT receiver FROM phone_calls WHERE caller IN (
        SELECT phone_number FROM people WHERE name IN ("Diana", "Bruce")
    )
    AND day=28 AND month=7 AND year=2021 AND duration<60
);
-- list 2 people: Philip<-Diana, Robin<-Bruce --suspected accomplice

-- Look for the theif, info: left Fiftyville on the earliest flight of the next day
SELECT name FROM people WHERE passport_number IN (
    SELECT passport_number FROM passengers WHERE flight_id IN (
        SELECT id FROM flights
        WHERE day=29 AND month=7 AND year=2021 AND origin_airport_id IN (
            SELECT id FROM airports WHERE city="Fiftyville"
        )
        ORDER BY hour LIMIT 1
    )
) AND name IN ("Diana", "Bruce");
-- lists Bruce, most likely suspect, Hence Robin is most likely accomplice

-- Get first flight out of Fiftyville on 29/07/2021
SELECT city FROM airports WHERE id IN (
    SELECT destination_airport_id FROM flights
    WHERE day=29 AND month=7 AND year=2021 AND origin_airport_id IN (
        SELECT id FROM airports WHERE city="Fiftyville"
    )
    ORDER BY hour LIMIT 1
);
-- The city the suspect may have fled to is New York City
