# Week 3 — Authenticated Handshake (Step‑by‑Step)

## Sequence Breakdown

1. Alice: generate ephemeral X25519 private key $a$ and public key $A$ (32 bytes).
2. Alice: sign $A$ with her long‑term RSA‑2048 private key: $\mathrm{Sig}_A = \mathrm{Sign}_{sk_A}(A)$ (PSS+SHA256, ~256 bytes).
3. Alice → Bob: send `Sig_A || A`.
4. Bob: receive `Sig_A || A`; verify $\mathrm{Verify}_{pk_A}(\mathrm{Sig}_A, A)$. Abort on failure.
5. Bob: generate ephemeral X25519 private key $b$ and public key $B$ (32 bytes).
6. Bob: sign $B$ with his long‑term RSA‑2048 private key: $\mathrm{Sig}_B = \mathrm{Sign}_{sk_B}(B)$.
7. Bob → Alice: send `Sig_B || B`.
8. Alice: receive `Sig_B || B`; verify $\mathrm{Verify}_{pk_B}(\mathrm{Sig}_B, B)$. Abort on failure.
9. Alice: compute shared secret $S = \mathrm{X25519}(a, B)$ (mathematically $S = g^{ab}$).
10. Bob: compute shared secret $S = \mathrm{X25519}(b, A)$ (same $S = g^{ab}$).
11. Both: derive symmetric AES key $K = \mathrm{HKDF\text{-}SHA256}(\mathrm{IKM}=S, \;\mathrm{length}=32,\;\mathrm{info}=\texttt{"handshake data"})$.
12. Alice: encrypt payload with AES‑GCM (nonce 12B, tag 16B) using $K$ and send `nonce || tag || ciphertext`.
13. Bob: decrypt and verify AES‑GCM tag with $K$, then process plaintext.


## Key Delineation

- **Ephemeral keys (session):** X25519 keys — private values $a, b$ and public points $A, B$.
  - Purpose: provide a fresh Diffie–Hellman shared secret per session and enable forward secrecy.
  - Property: ephemeral; compromise later does not reveal past session keys if $a,b$ are unrecovered.

- **Long‑term identity keys:** RSA‑2048 identity keypairs (`sk_A`/`pk_A`, `sk_B`/`pk_B`).
  - Purpose: authenticate the origin of an ephemeral X25519 public value by signing it.
  - Property: persistent identity binding; used only for signatures (not for deriving session secrets).


## Design Defense — Why sign the X25519 public bytes before transmission

Problem if unsigned: an active adversary M can perform a man‑in‑the‑middle (MitM) by substituting ephemeral public values. Without authentication:

- Alice sends $A=g^{a}$, Bob sends $B=g^{b}$.
- Attacker M intercepts and substitutes $A' = g^{a'}$ to Bob and $B' = g^{b'}$ to Alice.
- Alice computes $S_A = g^{a b'}$, Bob computes $S_B = g^{a' b}$, while M knows both $g^{a b'}$ and $g^{a' b}$ and can decrypt/relay messages.

Thus unauthenticated DH is vulnerable to MitM and Unknown‑Key‑Share (UKS) attacks.

Authentication by signing fixes this: each ephemeral public key is accompanied by a signature under the sender's long‑term private key. Acceptance requires

$$\mathrm{Verify}(pk_B, \mathrm{Sig}_B, B) = \text{True}$$

which implies (under the EUF‑CMA security of RSA‑PSS) that the sender holds $sk_B$ and intentionally produced $B$. An attacker who tries to substitute $B'$ must provide a matching signature $\mathrm{Sig}'$ such that

$$\mathrm{Verify}(pk_B, \mathrm{Sig}', B') = \text{True},$$

but forging such a pair without $sk_B$ is computationally infeasible. Therefore substitution attacks are prevented.

Mathematically, the honest shared secret is

$$S = g^{ab}$$

and both sides only compute $S$ from ephemeral values that have been proven (by signatures) to originate from the claimed identities. This enforces authentication of the DH exchange and prevents MitM and UKS.


### Security properties achieved

- Authentication of peers (via RSA signatures over ephemeral X25519 pubs).
- Forward secrecy (ephemeral X25519 keys provide DH secrecy independent of long‑term key compromise).
- Resistance to active MitM and UKS attacks (signature binding prevents substitution and impersonation).


---

If you want this as a diagram or with added formal proofs (game‑based statements), tell me which style you prefer and I will extend the document.
