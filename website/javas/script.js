$(document).ready(function() {
	// When a link with the class of navbar is clicked
	$(".navbar a").click(function(e) {
		// Prevent the default action of the link
		e.preventDefault();

		// Get the target (the href attribute of the clicked link)
		var target = $(this).attr("href");

		// Animate the scroll to the target
		$("html, body").animate({
			scrollTop: $(target).offset().top
		}, 500); // 1000 milliseconds for the scroll duration
	});
});