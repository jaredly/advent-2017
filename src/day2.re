
let numberList = text => {
  let numbers = Js.String.splitByRe([%bs.re "/\s+/g"], text);
  Array.map(int_of_string, numbers)
};

let numberLines = (text) => Js.String.split("\n", text) |> Array.map(String.trim) |> Js.Array.filter(x => String.length(x) > 0) |> Array.map(numberList);

let listDiff = numbers => Array.fold_left(max, min_int, numbers) - Array.fold_left(min, max_int, numbers);

let checkSum = lines => Array.map(listDiff, lines) |> Array.fold_left((+), 0);

let solution = text => checkSum(numberLines(text));

let input = {|5 1 9 5
7 5 3
2 4 6 8|};

Js.log2(solution(input), "18");

let find_divisor = (others, number, index) => {
  let len = Array.length(others);
  let rec loop = (i) => if (i >= len) {
    None
  } else if (i === index) {
    loop(i + 1)
  } else if (number mod others[i] === 0) {
    Some(number / others[i])
    /* Some((number, others[i], number / others[i])) */
  } else {
    loop(i + 1);
  };
  loop(0)
};

let maybeFind = (array, finder) => {
  let rec loop = i => switch (finder(i, array[i])) {
  | None => i + 1 == Array.length(array) ? None : loop(i + 1)
  | Some(x) => Some(x)
  };
  loop(0)
};

let forceUnwrap = (message, opt) => switch opt { | None => failwith(message) | Some(x) => x };

let divisors = numbers => maybeFind(numbers, (index, number) => find_divisor(numbers, number, index)) |> forceUnwrap("Unable to find the divisors");

let solution2 = text => numberLines(text) |> Array.map(divisors) |> Array.fold_left((+), 0);

let input = {|
5 9 2 8
9 4 7 3
3 8 6 5
|};

Js.log2(solution2(input), 9);