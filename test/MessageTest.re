open TestFramework;
open Vim;

let reset = () => Helpers.resetBuffer("test/testfile.txt");
let input = s => ignore(Vim.input(s));

describe("Messages", ({test, _}) => {
  test("echo dispatches message", ({expect, _}) => {
    let _ = reset();
    let (_context, effects) = command("echo 'hello'");

    expect.bool(
      effects
      |> Effect.matches(msg =>
           msg
           == Effect.Message({
                priority: Types.Info,
                title: "",
                message: "hello",
              })
         ),
    ).
      toBe(
      true,
    );
  });
  test("echoerr dispatches error message", ({expect, _}) => {
    let _ = reset();
    let (_context, effects) = command("echoerr 'aproblem'");

    expect.bool(
      effects
      |> Effect.matches(msg =>
           msg
           == Effect.Message({
                priority: Types.Error,
                title: "",
                message: "aproblem",
              })
         ),
    ).
      toBe(
      true,
    );
  });
});
