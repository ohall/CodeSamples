package s44jr_activities.collections.components{
	import mx.core.ISelectableList;
	import mx.core.IVisualElement;
	import mx.core.mx_internal;
	
	import s44jr_activities.collections.events.GroupStackEvent;
	
	import spark.components.Group;
	
	use namespace mx_internal;
	
	[Event(name="contentAdded", type="s44jr_activities.collections.events.GroupStackEvent")]
	[Event(name="pageChanged", 	type="s44jr_activities.collections.events.GroupStackEvent")]
	public class GroupStack extends Group implements ISelectableList{
		
		/**
		 * Takes and array of mxml objects and allows developer to navigate them
		 * similar to mx ViewStack.
		 * */
		public function GroupStack(){
			super();
		}
	
		private var _lastIndex		 		: int = -1;
		private var _selectedIndex			: int;		
		private var _selectedIndexChanged	: Boolean;
		
		
		/// Basic interface ///
		
		/**
		 * Takes and array of mxml objects to be added to the stack
		 * */
		public function setContentArray(pContentArray:Array):void{
			mxmlContent = pContentArray;
		}
		  
		public function get currentPage():int{ 
			return selectedIndex;
		}
		
		public function get totalPages():int{
			return length;
		}
		
		public function goToNextPage():void{
			if( selectedIndex < length-1){
				selectedIndex++
			}
				
		}
		
		public function goToPreviousPage():void{
			if(selectedIndex > 0){
				selectedIndex--
			}
		}
		
		public function goToPage(pPageToGet:uint):void{
			if(pPageToGet < length){
				selectedIndex = pPageToGet;
			}
		}
		
		/// Other interface methods ///
		
		public function get selectedIndex():int{ 
			return _selectedIndex; 
		}
		
		public function get length():int{
			return numElements;
		}
		
		public function set selectedIndex(value:int):void{
			if (value == _selectedIndex){ return; }
			_lastIndex = _selectedIndex;
			_selectedIndex = value;
			_selectedIndexChanged = true;
			invalidateProperties();
			dispatchEvent(new GroupStackEvent(GroupStackEvent.PAGE_CHANGED));
		}
		
		override public function set mxmlContent(value:Array):void{
			super.mxmlContent = value;
			
			value.forEach(function (item:IVisualElement, index:int, array:Array):void{
				item.visible = (index == _selectedIndex) ? true : false;
			});
			dispatchEvent(new GroupStackEvent(GroupStackEvent.CONTENT_ADDED));
		}

		/**
		 *  A reference to the currently visible child container.
		 *  The default is a reference to the first child.
		 *  If there are no children, this property is <code>null</code>.
		 *
		 *  <p><strong>Note:</strong> You can only set this property in an
		 *  ActionScript statement, not in MXML.</p>
		 */
		public function get selectedChild():IVisualElement{
			return IVisualElement(getElementAt(_selectedIndex));
		}
	
		public function set selectedChild(value:IVisualElement):void{
			selectedIndex = getElementIndex(value);
		}
		
		public function addItem(item:Object):void{
			addElement(IVisualElement(item));
		}
		
		public function addItemAt(item:Object, index:int):void{
			addElementAt(IVisualElement(item), index);
		}
		
		public function getItemAt(index:int, prefetch:int=0):Object{
			return getElementAt(index);
		}
		
		public function getItemIndex(item:Object):int{
			return getElementIndex(IVisualElement(item));
		}
		
		public function itemUpdated(item:Object, property:Object=null, oldValue:Object=null, newValue:Object=null):void{
		}
		
		public function removeAll():void{
			removeAllElements();
		}
		
		public function removeItemAt(index:int):Object{
			return removeElementAt(index);
		}
		
		public function setItemAt(item:Object, index:int):Object{
			var removedElement:IVisualElement = removeElementAt(index);
			addElementAt(IVisualElement(item), index);
			return removedElement;
		}
		
		public function toArray():Array{
			return getMXMLContent();
		}
		
		override protected function commitProperties():void{
			super.commitProperties();
			
			if (_selectedIndexChanged){
				_selectedIndexChanged = false;
				if (_lastIndex >= 0){
					getElementAt(_lastIndex).visible = false;
				}
				getElementAt(_selectedIndex).visible = true;
			}
		}
	}
}
