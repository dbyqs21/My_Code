using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Adapter
{
    using System.Collections;
    using System;

    interface IStake
    {
        void Push(Object item);
        object Pop();
        Object Peek();
    }
    class MyStake : IStake
    {
        ArrayList list;
        public MyStake()
        {
            list=new ArrayList();
        }

        void Push(Object item)
        {
            list.Add(item);
        }

        Object Pop()
        {
            return list.RemoveAt(list.Count - 1);
        }

        Object Peek()
        {

        }
      
    }
}
