;; Use guix environment -m manifest.scm
;; Or with direnv:
;; use_guix -m manifest.scm
(specifications->manifest
  '("node"
    "ccls"
    "gcc-toolchain@10.2.0"))

