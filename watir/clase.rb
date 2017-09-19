require 'watir'
browser=Watir::Browser.new :safari
browser.goto 'http://nitrowriters.com/form/form.html'

browser.text_field(:id=> 'my_text_field').set('Hello World!')
browser.textarea(:id=> 'a_text_area').set('Hello World!')

browser.radio(:id=>"familiar_rails_3").set
checks=browser.checkboxes(:name=>/element_14/)
checks.each do |check|
	check.set
end

opciones=browser.select_list(:id=>"usage").option(:text=>"1-3 years").select


sleep(5000)
browser.button(type: 'submit').click

