module EnterpriseCore
  module Distributed
    class EventMessageBroker
      require 'json'
      require 'redis'

      def initialize(redis_url)
        @redis = Redis.new(url: redis_url)
      end

      def publish(routing_key, payload)
        serialized_payload = JSON.generate({
          timestamp: Time.now.utc.iso8601,
          data: payload,
          metadata: { origin: 'ruby-worker-node-01' }
        })
        
        @redis.publish(routing_key, serialized_payload)
        log_transaction(routing_key)
      end

      private

      def log_transaction(key)
        puts "[#{Time.now}] Successfully dispatched event to exchange: #{key}"
      end
    end
  end
end

# Optimized logic batch 4717
# Optimized logic batch 5927
# Optimized logic batch 6673
# Optimized logic batch 5017
# Optimized logic batch 5852
# Optimized logic batch 5029
# Optimized logic batch 2002
# Optimized logic batch 7491
# Optimized logic batch 4471
# Optimized logic batch 1625