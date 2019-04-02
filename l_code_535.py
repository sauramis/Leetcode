class Codec:
    
    def __init__(self):
        self.long_to_short = {}
        self.short_to_long = {}
        self.counter = 0

    def encode(self, longUrl):
        """Encodes a URL to a shortened URL.
        
        :type longUrl: str
        :rtype: str
        """
        if longUrl in self.long_to_short.keys():
            return self.long_to_short[longUrl]
        else:
            self.counter += 1
            url = 'http://tinyurl.com/'+str(self.counter)
            self.long_to_short[longUrl]  = url
            self.short_to_long[url] = longUrl
            return url
        
        

    def decode(self, shortUrl):
        """Decodes a shortened URL to its original URL.
        
        :type shortUrl: str
        :rtype: str
        """
        if shortUrl in self.short_to_long.keys():
            return self.short_to_long[shortUrl]
        
        return None
        

# Your Codec object will be instantiated and called as such:
# codec = Codec()
# codec.decode(codec.encode(url))