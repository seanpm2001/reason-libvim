type yankType =
| Block
| Line
| Char;

type yankOperator =
| Delete
| Yank;

type t = {
  lines: array(string),
  yankType: yankType,
  register: char,
  operator: yankOperator,
  startLine: int,
  startColumn: int,
  endLine: int,
  endColumn: int,
};

let dCode = Char.code('d');

let create = (~lines, ~yankTypeInt, ~operator: int, ()) =>  {

  /* NOTE: This must be kept in sync with the definitions of MBLOCK/MLINE/MCHAR
     in vim.h
   */
  let yankType = switch(yankTypeInt) {
  | 0 => Char
  | 1 => Line
  | 2 => Block
  | _ => Line
  };

  let op = switch(operator) {
  | v when v == dCode => Delete
  | _ =>  Yank
  };

{
  lines,
  yankType,
  operator: op,
  register: 'a',
  startLine: 1,
  endLine: 2,
  startColumn: 1,
  endColumn: 1,
};

};