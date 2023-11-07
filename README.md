# CatMD

CatMD is a command-line tool that prints the file content as Markdown format.

## Table of Contents

- [Example](#example)
- [Installation](#installation)
- [Usage](#usage)
- [Contributing](#contributing)
- [License](#license)

## Example

Input:

```shell
cat README.md LICENSE
```

Output:

````text
*README.md*

```md
(The content of README.md)
```

*LICENSE*

```
(The content of LICENSE)
```
````

## Installation

To install CatMD, follow these steps:

1. Clone the repository: `git clone https://github.com/pluveto/catmd.git`
2. Navigate to the project directory: `cd catmd`
3. Build the executable: `make`
4. Install CatMD: `make install` (`INSTALL_DIR` can be specified, default is `/usr/local/bin`)

## Usage

CatMD can be used as follows:

```shell
catmd [options] <file ...>
```

Options:

- `-h, --help`: Output usage information
- `-v, --version`: Output the version number

Examples:

```shell
catmd README.md
catmd file1.md file2.md
```

## Contributing

Contributions are welcome! Here's how you can contribute to the project:

1. Fork the repository.
2. Create a new branch: `git checkout -b feature/your-feature-name`
3. Make your changes and commit them: `git commit -am 'feat: add some feature'`
4. Push the branch to your forked repository: `git push origin feature/your-feature-name`
5. Open a pull request.

Please ensure that your code follows the project's coding style and includes appropriate tests.

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.
