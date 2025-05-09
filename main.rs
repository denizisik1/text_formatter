use std::env;
use std::fs::{self, File};
use std::io::{self, BufRead, BufReader, BufWriter, Write};
use tempfile::NamedTempFile;

fn trailing_whitespace(filename: &str) -> io::Result<()> {
    let input = File::open(filename)?;
    let reader = BufReader::new(input);

    let mut temp_file = NamedTempFile::new()?;
    {
        let mut writer = BufWriter::new(&mut temp_file);

        for line_result in reader.lines() {
            let line = line_result?;
            let trimmed = line.trim_end(); // removes trailing whitespace
            writeln!(writer, "{}", trimmed)?;
        }
    }

    temp_file.persist(filename)?; // overwrite original file
    Ok(())
}

fn main() {
    let args: Vec<String> = env::args().collect();

    if args.len() != 2 {
        eprintln!("Usage: {} <filename>", args[0]);
        std::process::exit(1);
    }

    if let Err(e) = trailing_whitespace(&args[1]) {
        eprintln!("Error processing file: {}", e);
        std::process::exit(1);
    }
}
