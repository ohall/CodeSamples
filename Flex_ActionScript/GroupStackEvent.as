package s44jr_activities.collections.events{
	import flash.events.Event;
	public class GroupStackEvent extends Event{
		public static const CONTENT_ADDED	: String = "contentAdded";
		public static const PAGE_CHANGED	: String = "pageChanged";
		
		private var eventType:String;
		
		public function GroupStackEvent(type:String){
			eventType = type;
			super(type, false, false);
		}
		
		override public function clone():Event{
			return new GroupStackEvent(eventType);
		}
		
	}
}