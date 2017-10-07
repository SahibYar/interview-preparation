//
// Created by Sahib Yar on 10/7/17.
//

/*
 * Consider the following attempt to allocate a 10-element array of pointers
 * to doubles and initialize the associated double values to 0.0. Rewrite the
 * following (incorrect) code to do this correctly. (Hint: Storage for the
 * doubles needs to be allocated.)
 *
 *      double* dp[10]
 *      for (int i = 0; i < 10; i++) dp[i] = 0.0;
 *
 */
int main()
{
    double *dp = new double[10];
    for (int i = 0; i < 10; i++) { dp[i] = 0.0; }
    delete[] dp;
    return EXIT_SUCCESS;
}