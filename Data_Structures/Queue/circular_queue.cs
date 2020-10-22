using System;
using System.Collections;

namespace belphegorS.DataStructures
{
	/// <summary>
	/// Summary description for CsCircularQueue.
	/// </summary>
	public class CircularQueue
	{
		private int nMaxSize;
		private int nFrontPosition;
		private int nRearPosition;
		private ArrayList alstQueueContent;

		public CircularQueue(int MaxSize)
		{
			nMaxSize = MaxSize;
			nFrontPosition = 0;
			nRearPosition= -1;
			alstQueueContent = new ArrayList(MaxSize);
			for(int i = 0;i<nMaxSize;i++)
				alstQueueContent.Add(null);
			
 		}
		public void ResetQueue()
		{
			for(int i = 0;i<nMaxSize;i++)
				alstQueueContent[i] = null;
			nFrontPosition = 0;
			nRearPosition = -1;
		}
		public int FrontPosition
		{
			get
			{
				return nFrontPosition;
			}
		}
		public int RearPosition
		{
			get
			{
				return nRearPosition;
			}
		}
		public bool Enqueue(object obj)
		{
			if((nRearPosition == (nMaxSize-1) && nFrontPosition==0) ||((nRearPosition!=-1)&&(nRearPosition+1)==nFrontPosition))
				return false;

			if(nRearPosition == (nMaxSize -1) && nFrontPosition > 0)
			{
				nRearPosition = -1;
			}
			
			nRearPosition+=1;
			alstQueueContent[nRearPosition] = obj;
			if((nRearPosition-1) == nFrontPosition && alstQueueContent[nFrontPosition]==null)
				nFrontPosition = nFrontPosition+1;
			return true;
		}

		public object Dequeue()
		{
				object Output = "Empty" ;
				if(alstQueueContent[nFrontPosition] != null)
				{
					Output = alstQueueContent[nFrontPosition];
					alstQueueContent[nFrontPosition]=null;
					if((nFrontPosition+1)<nMaxSize && alstQueueContent[nFrontPosition+1] !=null)
						nFrontPosition += 1;
					else if(alstQueueContent[0] !=null && (nFrontPosition+1)== nMaxSize)
						nFrontPosition = 0;
					
				}
				return Output;	
		}
		private bool IsQueueFull()
		{
			if(nFrontPosition==(nRearPosition-1))
			{
				return true;
			}
			return false;
		}
	}
}
