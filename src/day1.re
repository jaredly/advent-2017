
let digitSum = (digits) => {
  let last = digits[Array.length(digits) - 1];
  Array.fold_left(
    ((total, prev), current) => (prev === current ? total + current : total, current),
    (0, last),
    digits
  ) |> fst
};

let digitList = text => {
  let digits = Js.String.split("", text);
  Array.map(int_of_string, digits)
};

let solution = text => {
  digitSum(digitList(text))
};

/* Js.log2(solution("1111"), 4);
Js.log2(solution("1122"), 3);
Js.log2(solution("1234"), 0);
Js.log2(solution("91212129"), 9); */

let halfway = (len, i) => {
  (i + len/2) mod len
};

let digitHalfSum = digits => {
  let len = Array.length(digits);
  Array.fold_left(
    ((total, i), current) => (
      current == digits[halfway(len, i)] ? total + current : total,
      i + 1
    ),
    (0, 0),
    digits
  ) |> fst
};

let solution2 = text => digitHalfSum(digitList(text));

/* Js.log2(solution2("1212"), 6);
Js.log2(solution2("1221"), 0);
Js.log2(solution2("123425"), 4);
Js.log2(solution2("123123"), 12);
Js.log2(solution2("12131415"), 4); */