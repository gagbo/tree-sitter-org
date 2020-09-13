{ pkgs ? import <nixpkgs> {} }:
  pkgs.mkShell {
    buildInputs = [ 
      pkgs.nodejs-14_x
      pkgs.gcc10
    ];
}
