using System;
using System.Collections;
using System.Collections.Generic;
using System.Reflection;
using Microsoft.Extensions.DependencyInjection;
using System.IO;
using System.Text;
using System.Linq;

namespace ConsoleAppPractice
{
    class Program
    {
        static void Main()
        {
            //线性同余法（Linear Congruential Method）来生成一个随机数列，
            //这种方法需要设置四个非负整数参数 ，
            //按照下面的公式生成出一系列随机数 
            //Xn + 1 = (aXn+c)modm
            //由于栋栋需要的随机数是 0,1,\dots,g-10,1,…,g−1 之间的，
            //他需要将 Xn除以 g取余得到他想要的数，即 Xnmodg
            //11 8 7 1 5 3     输出：2
            Console.WriteLine(new Solution().FindNum(11,8,7,1,5,3));
        }

    }
    class Matrix
    {
        private int[][] values;
        public int rowSize { get; set; }
        public int colSize { get; set; }
        public Matrix(int rowSize,int colSize)
        {
            this.rowSize = rowSize;
            this.colSize = colSize;
            values = new int[rowSize][];
            for(int i = 0; i < rowSize; i++)
            {
                values[i] = new int[colSize];
            }
        }
        public int[] this [int index]
        {
            get
            {
                return this.values[index];
            }
        }
        public static Matrix operator *(Matrix matrix1, Matrix matrix2)
        {
            if (matrix1.colSize != matrix2.rowSize) return null;
            Matrix result = new Matrix(matrix1.rowSize, matrix2.colSize);
            for (int i = 0; i < result.rowSize; i++)
            {
                for (int j = 0; j < result.colSize; j++)
                {
                    for (int k = 0; k < matrix1.colSize; k++)
                    {
                        result[i][j] += matrix1[i][k] * matrix2[k][j];
                    }
                }
            }
            return result;
        }
        public void Normalised()
        {
            int min = rowSize > colSize ? colSize : rowSize;
            for (int i = 0; i < min; i++)
            {
                values[i][i] = 1;
            }
        }
        public void PrintMatrix()
        {
            for (int i = 0; i < rowSize; i++)
            {
                for (int j = 0; j < colSize; j++)
                {
                    Console.Write(values[i][j]);
                }
                Console.WriteLine();
            }
        }
    }
    class Solution
    {
        public int FindNum(int m,int a,int c,int x,int n,int g)
        {
            Matrix matrix = new Matrix(2, 2);
            matrix[0][0] = a;
            matrix[0][1] = 1;
            matrix[1][1] = 1;
            matrix = FastPower(matrix, n);
            Matrix xMat = new Matrix(2, 1);
            xMat[0][0] = x;
            xMat[1][0] = c;
            Matrix result = matrix * xMat;
            return result[0][0]%m%g;
        }
        private Matrix FastPower(Matrix matrix,int n)
        {
            if (matrix.colSize != matrix.rowSize) return null;
            Matrix result = new Matrix(matrix.rowSize, matrix.colSize);
            result.Normalised();
            while (n > 0)
            {
                if ((n & 1 )== 1)
                {
                    result = result * matrix;
                }
                matrix = matrix * matrix;
                n = (n >> 1);
            }
            return result;
        }
    }
}