use rand::Rng;
use std::cmp::Ordering;
use std::io::{self, Write};

fn main() {
    println!("\nWelcome to the guessing game!");
    println!("You are to guess a randomly generated number btwn 1 and 40");

    let number: u16 = rand::thread_rng().gen_range(1..=40);
    let mut guess: String = String::with_capacity(32);
    let mut counter: u8 = 10;
    // println!("random number = {}", number);

    while counter > 0 {
        counter -= 1;
        guess.clear();

        print!("\nEnter your guess: ");
        io::stdout().flush().unwrap();
        io::stdin()
            .read_line(&mut guess)
            .expect("Failed to read input");

        let guess: u16 = match guess.trim().parse() {
            Ok(num) => num,
            Err(_) => {
                println!("input is not a number. {} attempts remaining", counter);
                continue;
            }
        };

        match guess.cmp(&number) {
            Ordering::Less => {
                println!(
                    "your guess is below the number. {} attempts remaining",
                    counter
                )
            }
            Ordering::Greater => {
                println!(
                    "your guess is above the number. {} attempts remaining",
                    counter
                )
            }
            Ordering::Equal => {
                println!("Your guess is correct. You win!!!\n");
                return;
            }
        }
    }
    println!("\nThe number was {}. You lose\n", number);
    return;
}
