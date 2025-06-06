def n_root(base, n, epsilon=1e-23, max_itt=1000):
    low = 0
    high = base
    for _ in range(max_itt):
        guess = (low + high) / 2
        if abs(guess**n - base) < epsilon:
            return guess
        elif guess**n < base:
            low = guess
        else:
            high = guess
    return guess

if __name__ == "__main__":
    import sys
    if len(sys.argv) != 3:
        print(f"Usage: {sys.argv[0]} <base> <exponent>")
        sys.exit(1)
    base = float(sys.argv[1])
    exponent = int(sys.argv[2])
    
    result = n_root(base, exponent)
    print(f"{result:.20f}")