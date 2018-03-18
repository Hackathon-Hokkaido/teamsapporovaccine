#!/usr/bin/env python3
import csv
from typing import List, Tuple


def load_csv() -> Tuple[List[str], List[List[str]]]:
    with open('hospitals.csv', 'r') as f:
        reader = csv.reader(f)
        header = next(reader)
        hospitals = list(reader)
        return header, hospitals


def main():
    header, hospitals = load_csv()
    for l in hospitals:
        line = f'{l[1]},{l[2]+l[3]+l[4]}'
        print(line)


if __name__ == '__main__':
    main()
