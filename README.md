# simple_shell
(team: Victor Adly,Fatima atichoury)
# Compilation
## Your shell will be compiled this way:-
`gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh`
## How to add Author file:-
`Bash script for generating the list of authors in git repo`
#!/bin/sh
git shortlog -se \
  | perl -spe 's/^\s+\d+\s+//' \
  | sed -e '/^CommitSyncScript.*$/d' \
  > AUTHORS 
  ```
