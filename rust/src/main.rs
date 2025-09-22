use std::io;

fn main() {
    println!("Enter a list of numbers separated by spaces:");

    // Read input from the user
    let mut input = String::new();
    io::stdin()
        .read_line(&mut input)
        .expect("Failed to read input");

    // Split the input string and parse numbers
    let numbers: Vec<f64> = input
        .split_whitespace()
        .filter_map(|s| s.parse::<f64>().ok())
        .collect();

    if numbers.is_empty() {
        println!("No valid numbers were entered.");
        return;
    }

    // Calculate stats
    let sum: f64 = numbers.iter().sum();
    let count = numbers.len();
    let average = sum / count as f64;
    let min = numbers.iter().cloned().fold(f64::INFINITY, f64::min);
    let max = numbers.iter().cloned().fold(f64::NEG_INFINITY, f64::max);

    // Display results
    println!("You entered {} numbers.", count);
    println!("Average: {:.2}", average);
    println!("Minimum: {}", min);
    println!("Maximum: {}", max);
}
