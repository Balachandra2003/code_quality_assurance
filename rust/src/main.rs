use std::collections::HashMap;
use std::io::{self, Write};

fn main() {
    let options: Vec<&'static str> = vec!["Apple", "Banana", "Cherry", "Date"];
    let mut votes: HashMap<String, usize> = HashMap::new();

    // Initialize vote counts
    for option in &options {
        votes.insert(option.to_string(), 0);
    }

    println!("Welcome to the Voting System!");
    println!("Poll question: What's your favorite fruit?");
    println!("Options:");
    for (i, opt) in options.iter().enumerate() {
        println!("  {}. {}", i + 1, opt);
    }
    println!("Type the option number to vote, or 'q' to quit.");

    loop {
        print!("Your vote: ");
        io::stdout().flush().unwrap();

        let mut input = String::new();
        io::stdin()
            .read_line(&mut input)
            .expect("Failed to read input");

        let input = input.trim();

        if input.eq_ignore_ascii_case("q") {
            println!("Voting ended. Final results:");
            print_results(&votes);
            break;
        }

        match input.parse::<usize>() {
            Ok(num) if num > 0 && num <= options.len() => {
                let choice = options[num - 1];
                *votes.get_mut(choice).unwrap() += 1;
                println!("You voted for: {}", choice);
                println!("Current results:");
                print_results(&votes);
            }
            _ => {
                println!("Invalid input, please enter a valid option number or 'q' to quit.");
            }
        }
    }
}

fn print_results(votes: &HashMap<String, usize>) {
    for (option, count) in votes {
        println!("{}: {}", option, count);
    }
    println!();
}
