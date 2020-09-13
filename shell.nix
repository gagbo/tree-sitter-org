# Use nix-shell
# Or with direnv:
# use_nix
{ pkgs ? import <nixpkgs> {} }:
  pkgs.mkShell {
    buildInputs = [ 
      pkgs.nodejs-14_x
      pkgs.gcc10
      pkgs.ccls
      pkgs.clang-tools
    ];
}
