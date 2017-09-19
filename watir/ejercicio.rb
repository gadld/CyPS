require 'watir'
browser=Watir::Browser.new :safari
browser.goto 'http://blazedemo.com/'


browser.button(type: 'submit').click

sleep(5)
#browser.button(:text => "Choose This Flight").click

browser.buttons(:class=>"btn").last.click

sleep(5)

browser.text_field(:id=> 'inputName').set('Hello World!')
browser.text_field(:id=> 'address').set('Hello World!')
browser.text_field(:id=> 'city').set('Hello World!')
browser.text_field(:id=> 'state').set('Hello World!')
browser.text_field(:id=> 'zipCode').set('Hello World!')
browser.text_field(:id=> 'creditCardNumber').set('Hello World!')
browser.text_field(:id=> 'creditCardMonth').set('Hello World!')
browser.text_field(:id=> 'creditCardYear').set('Hello World!')
browser.text_field(:id=> 'nameOnCard').set('Hello World!')
browser.button(type: 'submit').click





#cardType







