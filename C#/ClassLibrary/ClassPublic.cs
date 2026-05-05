using System.Data;

namespace ClassLibrary
{
    public class ClassPublic
    {
        public int pub;
        public const int pubConst = 0;
        public static int pubStat;
        public readonly int pubRead;

        protected int prot;
        private int priv;
        internal int inter;
        internal protected int intProt;
        public ClassPublic(int a, int b, int c)
        {
            pub = a;
            pubRead = b;
            pubStat = c;
        }
        public ClassPublic(int a, int b) : this (a, b, 0) {}
        public ClassPublic(int a) : this (a, a, a) {}
        public ClassPublic() : this (0, 1, 2) {}
        static ClassPublic()
        {
            pubStat = 0;
        }
        public int Method1()
        {
            return 0;
        }
        protected double Method2(int a)
        {
            return 0;
        }
        public static void Method3(int a, int b)
        {
            return;
            Console.WriteLine("dlfkjsdlkf");
        }
    }
    internal class ClassInternal
    {
        public int pub;
        protected int prot;
        private int priv;
        internal int inter;
        internal protected int intProt;
    }
    public class AnotherClass
    {
        ClassInternal intClass;
        public ClassPublic cp = new ClassPublic();
        public void Method()
        {
            Console.WriteLine(cp.pub);
            Console.WriteLine(cp.inter);
            Console.WriteLine(cp.intProt);
            cp.Method1();
            ClassPublic.Method3(1, 2);
        }
    }
}
