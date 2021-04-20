int solution(int X, int Y, int D) {
    int range = Y - X;

    int count = range / D;

    if(range % D != 0) count++;

    return count;
}