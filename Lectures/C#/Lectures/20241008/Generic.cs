using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _20241008
{
    /*
     일반화(Generic)
    - 클래스 또는 함수가 코드에 의해 선언되고 인스턴스화 될때까지 형식의 사용을 연기하는 일종의 디자인이다.
    - 기능을 구현한 뒤 자료형을 사용 당시에 지정하여 사용한다.
     
    <일반화 함수>
    -일반화는 자료형의 형식을 지정하지 않고 함수를 정의한다.
 
     //형식 매개변수 제약하기
    //일반화 자료형을 선언할때 제약조건을 걸어줌으로써 사용 당시 쓸 수 있는 자료형을 제한한다.
    //타입의 안정성을 높일 수 있다.

     */
    internal class Generic
    {
        #region Generic
        //제네릭의 기본 구현
        //public static void SwapValue<T>(ref T a,ref T b)
        //{
        //    T temp = a;
        //    a = b;
        //    b = temp;
        //}

        //public static void ArrayCopy<T>(T[] source, T[] output) 
        //{
        //    for(int i = 0; i< source.Length; ++i) 
        //    {
        //        output[i] = source[i];
        //    }
        //}
        //일반화 클래스
        class SafeArray<T>
        {
            private T[] array;
            //배열의 크기를 인자로 받아 초기화
            public SafeArray(int size) 
            {
                array = new T[size];
            }

            public void Set(int index,T value) 
            {
                //유효하지 않은 인덱스라면
                if (index > 0 || index >= array.Length) return;

                array[index] = value;
            }
            public T Get(int index) 
            {
                if(index < 0 || index >= array.Length) 
                {
                    //제네릭 타입 T의 기본값을 의미 EX) T가 int Type이라면 0을 리턴
                    return default(T);
                }

                return array[index];
            }
        }
        #endregion

        #region 제약조건

        /*
         where T : struct {} // struct로 제한(값 형식)
         where T : class {} // class로 제한(참조 형식)
         where T : new() {} // 매개변수가 없는 생성자가 있는 자료형
         where T : 기반 클래스 {} // 파생 클래스로 제한
         where T : 인터페이스 {} // 인터페이스를 포함한 자료형만으로 제한
         */

        class StructT<T> where T : struct { } //T는 구조체만 사용이 가능하다.
        class ClassT<T> where T : class { } //T는 클래스만 사용
        class NewT<T> where T : new() { } //T는 매개변수가 없는 생성자가 있는 자료형만
        class ParentT<T> where T : Parent { } //T는 파생클래스만 사용
        class InterfaceT<T> where T : IComparable { } //T는 인터페이스를 포함한 자료형만 사용가능
        class Parent { }
        class Child : Parent { }

        void Test() 
        {
            StructT<int> structT = new StructT<int>(); //int가 struct이기에 가능
            //ClassT<int> classT = new ClassT<int>(); //참조형식으로 제한을 걸었기에 값형식은 사용이 불가능하다
            InterfaceT<int> interfaceT = new InterfaceT<int>();//int 내부 코드에 IComparable 인터페이스를 포함하기에 가능하다.

        }
        #endregion

        #region where T : struct

        public static void SwapValue<T>(ref T a, ref T b) where T : struct 
        {
            T temp = a;
            a = b;
            b = temp;
        }

        public static void ArrayCopy<T>(T[] source, T[] output) where T : struct
        {
            for (int i = 0; i < source.Length; ++i)
            {
                output[i] = source[i];
            }
        }

        public static T Bigger<T>(T left, T right) where T : IComparable<T> 
        {
            if (left.CompareTo(right) > 0) 
            {
                return left;
            }
            else 
            {
                return right;
            }
        }
        #endregion


        static void Main(string[] args)
        {
            int x = 10;
            int y = 20;
            SwapValue(ref x, ref y);

            int[] iSrc = { 1,2,3,4,5 };
            int[] iDist = new int[iSrc.Length];
            ArrayCopy(iSrc, iDist);

            string[] sSrc = { "aaa", "bbb", "ccc" };
            string[] sDst = new string[sSrc.Length];

            //ArrayCopy<string>(sSrc, sDst);
        }
    }
}
